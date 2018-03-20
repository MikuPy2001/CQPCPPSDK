#pragma once
#include <string>
#include <vector>

//代表注释
class Commentses {
	std::string commentses;//注释
public:
	Commentses() = default;
	Commentses(std::string);
	Commentses(std::vector<std::string>);

	//设置注释
	virtual void setCommentses(std::string);
	//获取注释
	virtual std::string getCommentses();

	//获取ini格式的注释
	virtual std::string getCommentsesInIni();
};

//自定义集合
template<class T>
class INIvector {
protected:
	std::vector<T> list;//下属集合
	virtual bool equal(T&, std::string) = 0;
	virtual T New(std::string key) = 0;
public:
	//判断
	virtual bool has(std::string);

	//获取
	virtual T& get(std::string key);
	//获取
	virtual T & operator[](std::string key);

	//删除
	virtual void del(std::string key);

	//遍历
	virtual decltype(list.begin()) begin();
	virtual decltype(list.end()) end();
};

template<class T>
inline bool INIvector<T>::has(std::string key)
{
	for (T t : list)
		if (equal(t, key))return true;
	return false;
}

template<class T>
inline T & INIvector<T>::get(std::string key)
{
	for (T t : list)
		if (equal(t, key))return t;
	list.push_back(New(key));
	return list.back();
}

template<class T>
inline T & INIvector<T>::operator[](std::string key)
{
	return get(key);
}

template<class T>
inline void INIvector<T>::del(std::string key)
{
	for (auto b = begin(); b != end(); b++) {
		if (equal(*b, key)) { list.erase(b); return; }
	}
}

template<class T>
inline decltype(INIvector<T>::list.begin()) INIvector<T>::begin()
{
	return list.begin();
}

template<class T>
inline decltype(INIvector<T>::list.end()) INIvector<T>::end()
{
	return list.end();
}
