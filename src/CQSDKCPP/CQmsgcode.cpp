#include <string>
#include "..\CQSDK\CQmsgcode.h"
#include "..\CQSDK\CQTools.h"

using namespace std;
using namespace CQ;


/*
CQat::CQat(long long QQ) :QQ(QQ) {}

std::string CQat::tostring() const
{
	return std::string("[CQ:at,qq=") + to_string(QQ) + "]";
}

CQface::CQface(int faceid) : faceid(faceid) {}

CQface::CQface(face face) : faceid(face) {}

std::string CQface::tostring() const
{
	return std::string("[CQ:face,id=") + to_string(faceid) + "]";
}

CQrecord::CQrecord(string fileurl, bool magic) : fileurl(fileurl), magic(magic) {}

std::string CQrecord::tostring()const
{
	string s = std::string("[CQ:record,file=") + fileurl;
	if (magic)s += ",magic=true";
	return s += "]";
}

CQimage::CQimage(string file) :file(file) {}

std::string CQimage::tostring()const
{
	return std::string("[CQ:image,file=") + file + "]";
}
*/
//...
std::string CQ::code::image(std::string file)
{
	return std::string("[CQ:image,file=") + msg_encode(file, true) + "]";
}

std::string CQ::code::record(std::string fileurl, bool magic)
{
	string s = std::string("[CQ:record,file=") + fileurl;
	if (magic)s += ",magic=true";
	return s += "]";
}

std::string CQ::code::face(int faceid)
{
	return std::string("[CQ:face,id=") + to_string(faceid) + "]";
}

std::string CQ::code::face(CQ::face face)
{
	return code::face((int)face);
}

std::string CQ::code::at(long long QQ)
{
	return std::string("[CQ:at,qq=") + to_string(QQ) + "]";
}
