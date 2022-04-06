#include "Data.hpp"

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

int main(void)
{
	std::cout<<YELLOW<<"=== SERIALIZE & DESERIALIZE ===="<<DEFAULT<<std::endl;
	Data	*data = new Data;

	data->setArguments("serialize", 111);

	std::cout<<"data addr: "<<data<<std::endl;
	std::cout<<"data num: "<<data->getInteger()<<std::endl;
	std::cout<<"data str: "<<data->getString()<<std::endl<<std::endl;

	uintptr_t	ptr1 = data->serialize(data);
	Data		*test1 = data->deserialize(ptr1);

	std::cout<<"test1 addr: "<<test1<<std::endl;
	std::cout<<"test1 num: "<<test1->getInteger()<<std::endl;
	std::cout<<"test1 str: "<<test1->getString()<<std::endl<<std::endl;

	uintptr_t	ptr2 = data->serialize(test1);
	Data		*test2 = data->deserialize(ptr2);

	std::cout<<YELLOW<<"-------- VALUES CHANGE ---------"<<DEFAULT<<std::endl;
	test2->setArguments("deserialize", 999);

	std::cout<<"test1 addr: "<<test2<<std::endl;
	std::cout<<"test1 num: "<<test2->getInteger()<<std::endl;
	std::cout<<"test1 str: "<<test2->getString()<<std::endl<<std::endl;

	std::cout<<YELLOW<<"----------- RESULT -------------"<<DEFAULT<<std::endl;
	std::cout<<"data addr: "<<data<<std::endl;
	std::cout<<"data num: "<<data->getInteger()<<std::endl;
	std::cout<<"data str: "<<data->getString()<<std::endl<<std::endl;
	std::cout<<"ptr1 addr: "<<ptr1<<std::endl<<std::endl;
	std::cout<<"test1 addr: "<<test1<<std::endl;
	std::cout<<"test1 num: "<<test1->getInteger()<<std::endl;
	std::cout<<"test1 str: "<<test1->getString()<<std::endl<<std::endl;
	std::cout<<"ptr2 addr: "<<ptr2<<std::endl<<std::endl;
	std::cout<<"test1 addr: "<<test2<<std::endl;
	std::cout<<"test1 num: "<<test2->getInteger()<<std::endl;
	std::cout<<"test1 str: "<<test2->getString()<<std::endl<<std::endl;

	delete data;
	return (0);
}

/*
struct Data {
	std::string	str;
	int	num;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

int main(void)
{
	std::cout<<YELLOW<<"=== SERIALIZE & DESERIALIZE ===="<<DEFAULT<<std::endl;
	Data	*data = new Data;

	data->num = 256;
	data->str = std::string("serialize");

	std::cout<<"data addr: "<<data<<std::endl;
	std::cout<<"data num: "<<data->num<<std::endl;
	std::cout<<"data str: "<<data->str<<std::endl<<std::endl;

	uintptr_t	ptr1 = serialize(data);
	Data		*test1 = deserialize(ptr1);

	std::cout<<"test1 addr: "<<test1<<std::endl;
	std::cout<<"test1 num: "<<test1->num<<std::endl;
	std::cout<<"test1 str: "<<test1->str<<std::endl<<std::endl;

	uintptr_t	ptr2 = serialize(test1);
	Data		*test2 = deserialize(ptr2);

	std::cout<<YELLOW<<"-------- VALUES CHANGE ---------"<<DEFAULT<<std::endl;
	test2->num >>= 8;
	test2->str.clear();

	std::cout<<"test2 addr: "<<test2<<std::endl;
	std::cout<<"test2 num: "<<test2->num<<std::endl;
	std::cout<<"test2 str: "<<test2->str<<std::endl<<std::endl;

	std::cout<<YELLOW<<"----------- RESULT -------------"<<DEFAULT<<std::endl;
	std::cout<<"data addr: "<<data<<std::endl;
	std::cout<<"data num: "<<data->num<<std::endl;
	std::cout<<"data str: "<<data->str<<std::endl<<std::endl;
	std::cout<<"ptr1 addr: "<<ptr1<<std::endl<<std::endl;
	std::cout<<"test1 addr: "<<test1<<std::endl;
	std::cout<<"test1 num: "<<test1->num<<std::endl;
	std::cout<<"test1 str: "<<test1->str<<std::endl<<std::endl;
	std::cout<<"ptr2 addr: "<<ptr2<<std::endl<<std::endl;
	std::cout<<"test2 addr: "<<test2<<std::endl;
	std::cout<<"test2 num: "<<test2->num<<std::endl;
	std::cout<<"test2 str: "<<test2->str<<std::endl<<std::endl;

	delete data;
	return (0);
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
*/
