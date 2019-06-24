#include<iostream>
#include <fstream>

using namespace std;

class Date
{
public:
	string ruzhum;//入住日期
	string ruzhut;//入住时间
	string lidianm;//离店日期
	string lidiant;//离店时间
	int staytime;//入住天数
};
class Room
{
public:
	int num;//房号
	string type;//类型
	int price;//价格
	string ifguest;//状态（是否有人）
};
class Guest:public Date,public Room 
{
public:
	string name;//姓名
	string id;//身份证号
	string sex;//性别
};
class Manage:public Guest
{
    int allprice;
};
Room room[100];//存放登记的房间信息 
Guest guest[100];//存放登记的客人信息 
Manage manage[100];
Room room1[50];//用来存放文件里的房间信息
Guest guest1[50];//用来存放文件里的客人信息 
int num;
int size=0;
int num1;
int num2;
//信息录入的实现 
void xinxiluru()
{
	cout << "欢迎进入信息录入页面" << endl;
	cout << "请输入要添加的房间数：";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout<<"房间号-->";
		cin >> room[i].num;
		for(int j=0;j<50;j++)
		{
			if(room[i].num==room1[j].num)
			{
				cout<<room[i].num<<"房间已有，请输入下一个房间"<<endl; 
				break;
			}
			else
			{
		      cout << "房间类型-->";
		      cin >> room[i].type;
		      cout << "房间价格-->";
		      cin >> room[i].price;
		      cout<<"房间是否有人-->";
		      cin>>room[i].ifguest;
	         break;
			}	
		}
	}
}
//入住登记的实现 
void ruzhudengji()
{
	int num1;
    cout<<"欢迎进入入住登记页面"<<endl;
	cout<<"请输入需要入住的人数：";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"姓名-->";
		cin>>guest[i].name;
		cout<<"身份证号-->";
		cin>>guest[i].id;
		cout<<"性别-->";
		cin>>guest[i].sex;
		cout<<"入住日期-->";
		cin>>guest[i].ruzhum;
		cout<<"入住时间-->";
		cin>>guest[i].lidiant;
		cout<<"入住房间号-->";
		cin>>guest[i].num;
		cout<<"入住房间价格-->";
		cin>>guest[i].price;	
	} 
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<50;j++)
		{
		   if(guest[i].num==room1[j].num)
		   {
		   	room1[j].ifguest="有人";
		   }
		}	
	}
}
//退房结算 
void tuifangjiesuan()
{
    cout<<"欢迎进入退房结算界面"<<endl;
    cout<<"请输入需要退房的人数：";
    cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"请输入需要退房的人姓名：";
		cin>> manage[i].name;
		for(int j=0;j<num;j++)
		{
		if(manage[i].name==guest[j].name)
		{
		   cout<<"您的消费为： "<<guest[j].staytime*guest[j].price;
		}
		if(manage[i].name==guest1[j].name)
		{
			cout<<"您的消费为： "<<guest1[j].staytime*guest1[j].price;
		}
   	}
		cout<<"查无此人"<<endl;
	}
		
}
//客房浏览 
void kefangxinxiliulan()
{
	
	int num,i=0,j=0,tmp,tmp1;
	cout<<"请选择浏览方式：  1.按房号查找    2.浏览全部信息"<<endl;
	cin>>tmp1;
	if(tmp1==1)
	{
		cout<<"请输入需要查找的房间数-->";
        cin>>tmp;
        for(int s=0;s<tmp;s++)
        {
        cout<<"请输入要查找的房间号:-->";
        cin>>num;
        while(num==room1[j].num)
       {
   	    cout<<room1[j].num<<" "<<room1[j].type<<" "<<room1[j].price<<" "<<room1[j].ifguest<<endl;
   	  j++;
       }
	   }
	}
	if(tmp1==2)
	{
	    for(int k=0;k<50,room1[k].num!=0;k++)
	    {
	       cout<<room1[k].num<<" "<<room1[k].type<<" "<<room1[k].price<<" "<<room1[k].ifguest<<endl;
		}
	}
}
//浏览全部客户信息 
void liulankehuxinxi()
{
	for(int k=0;k<50,guest1[k].staytime!=0;k++)
	{
		cout<<guest1[k].name<<" "<<guest1[k].id<<" "<<guest1[k].sex<<" "<<guest1[k].ruzhum<<" "<<guest1[k].staytime<<endl;
	}
}
//存入text的内容 
void read(Room *room,Guest *guest)
{
	int i=0;
	int j=0;
	ifstream roomfile("Room.txt");
	if(!roomfile)
	cout<<"打开文件失败!"<<endl;
	ifstream guestfile("Guest.txt");
	if(!guestfile)
	cout<<"打开文件失败!"<<endl;
	while(!roomfile.eof())
	{
		roomfile>>room1[i].num>>room1[i].type>>room1[i].price>>room1[i].ifguest;
		i++;
	}
	while(!guestfile.eof())
	{
		guestfile>>guest1[j].num>>guest1[j].price>>guest1[j].name>>guest1[j].id>>guest1[j].sex>>guest1[j].ruzhum>>guest1[j].staytime;
		j++;
	}
	num1=i;
	num2=j;
	roomfile.close();
	guestfile.close();
}
//删除room.text的内容 
void delfile()
{
	string str="Room.txt";
	ofstream roomfile(str.c_str());
	  if (roomfile.good())
    {
        remove(str.c_str());
    }
    roomfile.close();
}
//将所有更新的数据重新写入文件内 
void write(Room *room,Guest *guest)
{
    ofstream roomfile;
	roomfile.open("Room.txt", std::ios_base::app);
	if(!roomfile)
	cout<<"打开文件失败!"<<endl;
	ofstream guestfile;
	guestfile.open("Guest.txt", std::ios_base::app);
	if(!guestfile)
	cout<<"打开文件失败!"<<endl;
	for(int i=0;i<num1;i++)
	{
		roomfile<<room1[i].num<<" "<<room1[i].type<<" "<<room1[i].price<<" "<<room1[i].ifguest<<endl;
	}
    for(int i=0;i<size;i++)
	{
		roomfile<<room[i].num<<" "<<room[i].type<<" "<<room[i].price<<" "<<room[i].ifguest<<endl;
	}
    for(int i=0;i<num;i++)
	{
		guestfile<<guest[i].num<<" "<<guest[i].price<<" "<<guest[i].name<<" "<<guest[i].id<<" "<<guest[i].sex<<" "<<guest[i].ruzhum<<" "<<guest[i].lidiant<<endl;
	}
	roomfile.close();
	guestfile.close();
}
//菜单打印 
void menu()
{
	    cout << "*******欢迎进入宾馆房间管理系统********" << endl;
		cout << "***************************************" << endl;
		cout << "            1.客房信息的录入           " << endl;
		cout << "            2.客人入住登记             " << endl;
		cout << "            3.客人退房结算             " << endl;
		cout << "            4.客房信息浏览             " << endl;
		cout << "            5.浏览全部客户信息         " << endl;
		cout << "            0.退出系统                 " << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
}
int main()
{
	
	read(room1,guest1);
	
	int choose = 0;
	do 
	{
		menu();
		cout << "请选择：" << endl;
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
			xinxiluru();
			break;
		case 2:
			ruzhudengji();
			break;
		case 3:
			tuifangjiesuan();
			break;
		case 4:
			kefangxinxiliulan();
			break;
		case 5:
			liulankehuxinxi();
			break;
		case 0:
			cout<<"退出";
			break;	
		default:
			cout << "输入非法，请重新输入！" << endl<<endl;
		}
	} while (choose);
	delfile();
	write(room,guest);
	system("pause");
	return 0;
}
