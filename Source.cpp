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
			//unique_ptr<object> p2(p1); //несколько умных указателей unique_ptr не могут указывать на один объект
		auto p3 = make_unique<Desc>(); 
			//auto p4 = p3;
		auto copy = move(p1); // p1 пустой
		p3 = move(p1);       // p3 пустой (объект на который указывал р3 удален)
	}
	printf("\n");
	{
		shared_ptr<Desc> p1(new Desc());
		shared_ptr<Desc> p2(p1);  //2 strong refs
		shared_ptr<Desc> p3; //nullptr
		p1 = move(p3);     //p1 пустой, 1 strong ref(p2)
		p2 = move(p3);     //p2 пустой, объект удален
	}

	return 0;
}














//{
//	Desc* p = new Desc(); printf("\n"); //вызов конструктора
////произойдет исключение
////shared_ptr<Desc> p1(p); //уничтожит уже удаленый объект по завершении программы
//	auto p1 = make_shared<Desc>(); printf("\n");//уничтожит объект по завершении программы, вызов конструктора
//	{
//		//shared_ptr<Desc> p2(p); //уничтожится после скобок, считает себя единственным владельцем p поэтому удаляет его
//		auto p2 = p1; printf("\n"); //2 strong refs
//	} //p2 выходит из области видимости, ничего не происходит
//}

////smart pointer unique_ptr and function make_unique()
//
//{
//	Desc* d1 = new Desc(); printf("\n"); //создается объект
//	unique_ptr<Desc> desc1(new Desc); printf("\n"); //создается объект
//	unique_ptr<Desc> desc5(d1); printf("\n\n"); //ничего не создается, копируется d1 в desc5
//
//	unique_ptr<Desc> f1 = make_unique<Desc>(5, 6); //конструктор с параметрами
//	f1->OK(); printf("\n\n");
//
//	//динамически выделенный массив длиной 5
//	//автоматическое определение типа данных с помощью ключевого слова auto
//	auto f2 = make_unique<Desc[]>(5); //5 раз вызовется дефолтный конструтор
//	//f2[0]->OK(); printf("\n\n"); //не работает почему то ????????????????????
//	printf("\n\n");
//
//	auto f3 = make_unique<Desc>(); printf("\n"); //дефолтный конструктор
//	auto f4 = move(desc1); printf("\n"); //desc1 is deleted, деструктор не вызывается
//	f3 = move(desc1); printf("\n\n"); //f3 is deleted, вызывается деструктор
//
//	//Desc* d2 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc2(d2); printf("\n");		//оба объекта пытаются удалить d2, ошибка
//	//unique_ptr<Desc> desc3(d2); printf("\n\n");
//
//	//Desc* d2 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc2(d2); printf("\n");		//не сработает, ошибка
//	//unique_ptr<Desc> desc3(desc2); printf("\n\n");
//
//	//Desc* d3 = new Desc(); printf("\n");
//	//unique_ptr<Desc> desc4(d3); printf("\n");		//попытка удалить то что уже было удалено, ошибка
//	//delete d3; printf("\n\n");
//} printf("\n\n");
//
//
////shared_ptr and make_shared()
//
//
//
//shared_ptr <Desc> ds3(new Desc); printf("\n"); //вызов конструктора
//shared_ptr <Desc> ds4(ds3); printf("\n"); //конструктор не вызывается, 2 strong refs
//shared_ptr <Desc> ds5; printf("\n"); //empty
//
//ds3 = move(ds5); printf("\n"); //ds3 empty, ds4 1 strong ref, деструктор не вызывается
//ds4 = move(ds5); printf("\n"); //деструктор
