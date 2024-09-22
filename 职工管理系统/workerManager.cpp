#include"workerManager.h"

WorkerManager::WorkerManager()
{
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if(!ifs.is_open())
    {
        //初始化记录人数
        this->m_EmpNum = 0;

        // 初始化数组指针
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2.文件数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        // 初始化记录人数
        this->m_EmpNum = 0;

        // 初始化数组指针
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3.文件存在且有数据
    int num = this->get_EmpNum();
    this->m_EmpNum = num;
    //存入数据
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->init_Emp();

}
// 展示菜单
void WorkerManager::Show_Menu()
{
    cout << "欢迎使用职工管理系统！" << endl;
    cout << "0.退出管理系统" << endl;
    cout << "1.增加职工信息" << endl;
    cout << "2.显示职工信息" << endl;
    cout << "3.删除离职职工" << endl;
    cout << "4.修改职工信息" << endl;
    cout << "5.查找职工信息" << endl;
    cout << "6.按照编号排序" << endl;
    cout << "7.清空所有文档" << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

// 添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量：" << endl;

    int addnum = 0;
    cin >> addnum;

    if(addnum>0)
    {
        int newsize = this->m_EmpNum + addnum;

        Worker **newSpace = new Worker *[newsize];

        if(this->m_EmpArray!=NULL)
        {
            for (int i = 0; i < this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        for (int i = 0; i < addnum;i++)
        {
            int id;
            string name;
            int dselect;

            cout << "请输入第" << i + 1 << "个新员工编号:" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个新员工姓名:" << endl;
            cin >> name;
            cout << "请选择职工岗位：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dselect;

            Worker *worker = NULL;
            switch(dselect)
            {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
                        }

            newSpace[this->m_EmpNum + i] = worker;
        }

        delete[] this->m_EmpArray;

        this->m_EmpArray = newSpace;
        this->m_EmpNum = newsize;

        //更新职工不为空
        this->m_FileIsEmpty = false;

        cout << "成功添加" << addnum << "名职工" << endl;

        //保存数据
        this->save();
    }
    else{
        cout << "输入有误" << endl;
    }


    system("pause");
    system("cls");
}
// 保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum;i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}
// 统计文件中的人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int num = 0;

    while(ifs>>id&&ifs>>name&&ifs>>did)
    {
        //统计人数
        num++;
    }
    return num;
}
// 初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if(did=1)
        {
            worker = new Employee(id, name, did);
        }
        if (did = 2)
        {
            worker = new Manager(id, name, did);
        }
        if (did = 3)
        {
            worker = new Boss(id, name, did);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    ifs.close();
}
// 显示职工
void WorkerManager::Show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum;i++)
        {
            //多态
            this->m_EmpArray[i]->showInfo();
        }
    }
}

// 删除职工
void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在" << endl;
    }
    else{
        cout << "输入删除职工编号" << endl;
        int id = 0;
        cin >> id;
        if(this->IsExist(id)!=-1)
        {
            for (int i = this->IsExist(id); i < this->m_EmpNum - 1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];

            }
            this->m_EmpNum--;
            this->save(); //同步文件
        }
        else{
            cout << "该职工不存在" << endl;
        }
    }

    system("pause");
    system("cls");
}

// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_Id==id)
        {
            index = i;
        }
    }
    return index;
}

// 修改职工
void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        cout << "输入修改职工编号" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);

        if (ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newid = 0;
            string newName = "";
            int dSelect = 0;
            cout << "查到：" << id << "号职工；请输入新编号；" << endl;
            cin >> newid;
            cout << "请输入新姓名:" << endl;
            cin >> newName;
            cout << "请选择职工岗位：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, newName, 1);
                break;
            case 2:
                worker = new Manager(id, newName, 2);
                break;
            case 3:
                worker = new Boss(id, newName, 3);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl;

            this->save();
        }

        else{
            cout << "该职工不存在" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 查找职工
void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在" << endl;
    }

    else{
        cout << "请输入查找方式" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按职工姓名查找" << endl;
        int select = 0;
        cin >> select;
        if(select==1){
            int id;
            cout << "输入职工编号:" << endl;
            int ret = IsExist(id);
            if(ret!=-1)
            {
                cout << "查找成功！该职工信息如下" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout << "查无此人" << endl;
            }
        }
        else if(select=2)
        {
            string name;
            cout << "请输入查找姓名" << endl;
            cin >> name;

            bool flag = false;

            for (int i = 0; i < m_EmpNum;i++)
            {
                if(this->m_EmpArray[i]->m_Name==name)
                {
                    cout << "查找成功，该职工信息如下" << endl;
                    this->m_EmpArray[i]->showInfo();

                    flag = true;
                }

            }
            if(flag=false)
            {
                cout << "查无此人" << endl;
            }
        }

        else{
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 排序职工
void WorkerManager::Sort_Emp()
{
   if(this->m_FileIsEmpty)
   {
       cout << "文件不存在" << endl;
       system("pause");
       system("cls");
   }
   else{

       for (int i = 0; i < m_EmpNum;i++)
       {
           int min = i;
           for (int j = i + 1; j < this->m_EmpNum;j++)
               if (this->m_EmpArray[min]->m_Id >this->m_EmpArray[j]->m_Id)
               {
                   min = j;
               }
            if(i!=min)
            {
                Worker *temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[min];
                this->m_EmpArray[min] = temp;
            }
       }
       cout << "排序成功，结果为：" << endl;
       this->save();
       this->Show_Emp();
   }
}
// 清空文件
void WorkerManager::Clean_Emp()
{
    cout << "确认清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;
    int select = 0;
    cin >> select;
    if(select==1)
    {
        //清空文件
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray!=NULL)
        {
            for (int i = 0; i < this->m_EmpNum;i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }

            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }
    system("pause");
    system("cls");
}
WorkerManager::~WorkerManager()
{
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        delete this->m_EmpArray[i];
        this->m_EmpArray[i] = NULL;
    }

    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
    this->m_EmpNum = 0;
    this->m_FileIsEmpty = true;
}