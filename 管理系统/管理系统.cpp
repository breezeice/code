#include<iostream>
#include <fstream>

using namespace std;

class Date
{
public:
	string ruzhum;//��ס����
	string ruzhut;//��סʱ��
	string lidianm;//�������
	string lidiant;//���ʱ��
	int staytime;//��ס����
};
class Room
{
public:
	int num;//����
	string type;//����
	int price;//�۸�
	string ifguest;//״̬���Ƿ����ˣ�
};
class Guest:public Date,public Room 
{
public:
	string name;//����
	string id;//���֤��
	string sex;//�Ա�
};
class Manage:public Guest
{
    int allprice;
};
Room room[100];//��ŵǼǵķ�����Ϣ 
Guest guest[100];//��ŵǼǵĿ�����Ϣ 
Manage manage[100];
Room room1[50];//��������ļ���ķ�����Ϣ
Guest guest1[50];//��������ļ���Ŀ�����Ϣ 
int num;
int size=0;
int num1;
int num2;
//��Ϣ¼���ʵ�� 
void xinxiluru()
{
	cout << "��ӭ������Ϣ¼��ҳ��" << endl;
	cout << "������Ҫ��ӵķ�������";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout<<"�����-->";
		cin >> room[i].num;
		for(int j=0;j<50;j++)
		{
			if(room[i].num==room1[j].num)
			{
				cout<<room[i].num<<"�������У���������һ������"<<endl; 
				break;
			}
			else
			{
		      cout << "��������-->";
		      cin >> room[i].type;
		      cout << "����۸�-->";
		      cin >> room[i].price;
		      cout<<"�����Ƿ�����-->";
		      cin>>room[i].ifguest;
	         break;
			}	
		}
	}
}
//��ס�Ǽǵ�ʵ�� 
void ruzhudengji()
{
	int num1;
    cout<<"��ӭ������ס�Ǽ�ҳ��"<<endl;
	cout<<"��������Ҫ��ס��������";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"����-->";
		cin>>guest[i].name;
		cout<<"���֤��-->";
		cin>>guest[i].id;
		cout<<"�Ա�-->";
		cin>>guest[i].sex;
		cout<<"��ס����-->";
		cin>>guest[i].ruzhum;
		cout<<"��סʱ��-->";
		cin>>guest[i].lidiant;
		cout<<"��ס�����-->";
		cin>>guest[i].num;
		cout<<"��ס����۸�-->";
		cin>>guest[i].price;	
	} 
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<50;j++)
		{
		   if(guest[i].num==room1[j].num)
		   {
		   	room1[j].ifguest="����";
		   }
		}	
	}
}
//�˷����� 
void tuifangjiesuan()
{
    cout<<"��ӭ�����˷��������"<<endl;
    cout<<"��������Ҫ�˷���������";
    cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"��������Ҫ�˷�����������";
		cin>> manage[i].name;
		for(int j=0;j<num;j++)
		{
		if(manage[i].name==guest[j].name)
		{
		   cout<<"��������Ϊ�� "<<guest[j].staytime*guest[j].price;
		}
		if(manage[i].name==guest1[j].name)
		{
			cout<<"��������Ϊ�� "<<guest1[j].staytime*guest1[j].price;
		}
   	}
		cout<<"���޴���"<<endl;
	}
		
}
//�ͷ���� 
void kefangxinxiliulan()
{
	
	int num,i=0,j=0,tmp,tmp1;
	cout<<"��ѡ�������ʽ��  1.�����Ų���    2.���ȫ����Ϣ"<<endl;
	cin>>tmp1;
	if(tmp1==1)
	{
		cout<<"��������Ҫ���ҵķ�����-->";
        cin>>tmp;
        for(int s=0;s<tmp;s++)
        {
        cout<<"������Ҫ���ҵķ����:-->";
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
//���ȫ���ͻ���Ϣ 
void liulankehuxinxi()
{
	for(int k=0;k<50,guest1[k].staytime!=0;k++)
	{
		cout<<guest1[k].name<<" "<<guest1[k].id<<" "<<guest1[k].sex<<" "<<guest1[k].ruzhum<<" "<<guest1[k].staytime<<endl;
	}
}
//����text������ 
void read(Room *room,Guest *guest)
{
	int i=0;
	int j=0;
	ifstream roomfile("Room.txt");
	if(!roomfile)
	cout<<"���ļ�ʧ��!"<<endl;
	ifstream guestfile("Guest.txt");
	if(!guestfile)
	cout<<"���ļ�ʧ��!"<<endl;
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
//ɾ��room.text������ 
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
//�����и��µ���������д���ļ��� 
void write(Room *room,Guest *guest)
{
    ofstream roomfile;
	roomfile.open("Room.txt", std::ios_base::app);
	if(!roomfile)
	cout<<"���ļ�ʧ��!"<<endl;
	ofstream guestfile;
	guestfile.open("Guest.txt", std::ios_base::app);
	if(!guestfile)
	cout<<"���ļ�ʧ��!"<<endl;
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
//�˵���ӡ 
void menu()
{
	    cout << "*******��ӭ������ݷ������ϵͳ********" << endl;
		cout << "***************************************" << endl;
		cout << "            1.�ͷ���Ϣ��¼��           " << endl;
		cout << "            2.������ס�Ǽ�             " << endl;
		cout << "            3.�����˷�����             " << endl;
		cout << "            4.�ͷ���Ϣ���             " << endl;
		cout << "            5.���ȫ���ͻ���Ϣ         " << endl;
		cout << "            0.�˳�ϵͳ                 " << endl;
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
		cout << "��ѡ��" << endl;
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
			cout<<"�˳�";
			break;	
		default:
			cout << "����Ƿ������������룡" << endl<<endl;
		}
	} while (choose);
	delfile();
	write(room,guest);
	system("pause");
	return 0;
}
