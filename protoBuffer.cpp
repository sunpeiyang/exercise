// test.proto ; protobuf command to compile the proto file, generate .h .cc file
package sun;
message helloworld
{
	required int32 id = 1;
	required string str = 2;
	optional int32 opt = 3;
}


//writer.cpp 文件 
#include "test.pb.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	sun::helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");

	fstream output("./log", ios::out | ios::trunc | ios::binary);

	if (!msg1.SerializeToOstream(&output))
	{
		cerr << "Failed to write msg." << endl;
		return -1;
	}

	return 0;
}


//reader.cpp 文件
#include "test.pb.h"
#include <iostream>
#include <fstream>

using namespace std;

void ListMsg(const sun::helloworld& msg)
{
	cout << msg.id() << endl;
	cout << msg.str() << endl;
}
int main()
{
	sun:: helloworld msg1;
	
	{
		fstream input("./log", ios::in|ios::binary);
		
		if (!msg1.ParseFromIstream(&input))
		{
			cerr << "Failed to parse address book." << endl;
			return -1;
		}
	}

	ListMsg(msg1);
}
