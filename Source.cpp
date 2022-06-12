#include <iostream>
#include <memory>
using namespace std;

class Desc
{
public:
	Desc()
	{
		printf("Desc()\n");
	}
	~Desc()
	{
		printf("~Desc()\n");
	}
};

int main()
{
	{
		unique_ptr<Desc> p1(new Desc());
			//unique_ptr<object> p2(p1); //��������� ����� ���������� unique_ptr �� ����� ��������� �� ���� ������
		auto p3 = make_unique<Desc>(); 
			//auto p4 = p3;
		auto copy = move(p1); // p1 ������
		p3 = move(p1);       // p3 ������ (������ �� ������� �������� �3 ������)
	}
	printf("\n");
	{
		shared_ptr<Desc> p1(new Desc());
		shared_ptr<Desc> p2(p1);  //2 strong refs
		shared_ptr<Desc> p3; //nullptr
		p1 = move(p3);     //p1 ������, 1 strong ref(p2)
		p2 = move(p3);     //p2 ������, ������ ������
	}

	return 0;
}














//{
//	Desc* p = new Desc(); printf("\n"); //����� ������������
////���������� ����������
////shared_ptr<Desc> p1(p); //��������� ��� �������� ������ �� ���������� ���������
//	auto p1 = make_shared<Desc>(); printf("\n");//��������� ������ �� ���������� ���������, ����� ������������
//	{
//		//shared_ptr<Desc> p2(p); //����������� ����� ������, ������� ���� ������������ ���������� p ������� ������� ���
//		auto p2 = p1; printf("\n"); //2 strong refs
//	} //p2 ������� �� ������� ���������, ������ �� ����������
//}

////smart pointer unique_ptr and function make_unique()
//
//{
//	Desc* d1 = new Desc(); printf("\n"); //��������� ������
//	unique_ptr<Desc> desc1(new Desc); printf("\n"); //��������� ������
//	unique_ptr<Desc> desc5(d1); printf("\n\n"); //������ �� ���������, ���������� d1 � desc5
//
//	unique_ptr<Desc> f1 = make_unique<Desc>(5, 6); //����������� � �����������
//	f1->OK(); printf("\n\n");
//
//	//����������� ���������� ������ ������ 5
//	//�������������� ����������� ���� ������ � ������� ��������� ����� auto
//	auto f2 = make_unique<Desc[]>(5); //5 ��� ��������� ��������� ����������
//	//f2[0]->OK(); printf("\n\n"); //�� �������� ������ �� ????????????????????
//	printf("\n\n");
//
//	auto f3 = make_unique<Desc>(); printf("\n"); //��������� �����������
//	auto f4 = move(desc1); printf("\n"); //desc1 is deleted, ���������� �� ����������
//	f3 = move(desc1); printf("\n\n"); //f3 is deleted, ���������� ����������
//
//	//Desc* d2 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc2(d2); printf("\n");		//��� ������� �������� ������� d2, ������
//	//unique_ptr<Desc> desc3(d2); printf("\n\n");
//
//	//Desc* d2 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc2(d2); printf("\n");		//�� ���������, ������
//	//unique_ptr<Desc> desc3(desc2); printf("\n\n");
//
//	//Desc* d3 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc4(d3); printf("\n");		//������� ������� �� ��� ��� ���� �������, ������
//	//delete d3; printf("\n\n");
//} printf("\n\n");
//
//
////shared_ptr and make_shared()
//
//
//
//shared_ptr <Desc> ds3(new Desc); printf("\n"); //����� ������������
//shared_ptr <Desc> ds4(ds3); printf("\n"); //����������� �� ����������, 2 strong refs
//shared_ptr <Desc> ds5; printf("\n"); //empty
//
//ds3 = move(ds5); printf("\n"); //ds3 empty, ds4 1 strong ref, ���������� �� ����������
//ds4 = move(ds5); printf("\n"); //����������
