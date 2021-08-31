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

//Multiple Inheritance
//Hybrid Inheritance

#include<iostream>

class student
{
protected:
	int r;
public:
	void getn(int a) { r = a; }
	void putn()
	{
		std::cout << "Roll Number : " << r << std::endl;
	}
};

class test :public student
{
protected:
	int m1, m2;
public:
	void getm(int a, int b)
	{
		m1 = a; m2 = b;
	}
	void putm()
	{
		std::cout << "Marks 1 : " << m1 << std::endl;
		std::cout << "Marks 2 : " << m2 << std::endl;
	}
};

class sports
{
protected:
	int s;
public:
	void gets(int z) { s = z; }
	void puts() { std::cout << "Sports : " << s << std::endl; }
};

class result :public sports, public test
{
protected:
	int total;
public:
	void display()
	{
		putn();
		putm();
		puts();
		
		total = s + m1 + m2;
		std::cout << "Total Marks : " << total << std::endl;
	}
};


int main()

{
	result student1;
	student1.getn(26);
	student1.getm(80, 85);
	student1.gets(80);
	student1.display();
}


//VirtualBaseClasses

#include <iostream>

class student
{
protected:
	int r;
public:
	void getn(int a)
	{
		r = a;
	}
	void putn()
	{
		std::cout << "Roll Number = " << r << std::endl;
	}
};

class test :public virtual student
{
protected:
	int m1, m2;
public:
	void getm(int a1, int a2) { m1 = a1; m2 = a2; }
	void putm()
	{
		std::cout << "Marks 1 : " << m1 << std::endl;
		std::cout << "Marks 2 : " << m2 << std::endl;
	}
};

class sports :virtual public student
{
protected:
	int s;
public:
	void gets(int z) { s = z; }
	void puts()
	{
		std::cout << "Sports marks is " << s << std::endl;
	}
};

class result :public sports, public test
{
	int total;
public:
	void display();
};

void result::display()
{
	total = m1 + m2 + s;
	putn();
	putm();
	puts();

	std::cout << "Total marks is " << total << std::endl;
}

int main()
{
	result r1;
	r1.getn(1);
	r1.getm(100, 90);
	r1.gets(60);
	r1.display();
}
