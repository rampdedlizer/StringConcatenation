#include<iostream>
#include<string>


class String
{
	int l;
	std::string name;
public:
	String() { l = 0; }
	String(std::string a) { name = a; }

	friend String concatenate(String, String);

	friend void display(String);
};

String concatenate(String o2, String o3)
{
	String A;
	A.name = o2.name + "  " + o3.name;
	return(A);
}
void display(String s1)
{
	std::cout << "  " << std::endl;
	std::cout << s1.name << std::endl;
	std::cout << "   " << std::endl;
}

int main()

{
	String s1;
	String s2("hello");
	String s3("world");

	String s4 = concatenate(s2, s3);

	display(s2);
	display(s3);
	display(s4);
}
