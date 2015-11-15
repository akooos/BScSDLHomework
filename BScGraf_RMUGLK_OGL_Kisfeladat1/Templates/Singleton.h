#ifndef SINGLETON_H
#define SINGLETON_H
template <class T>
class Singleton{
	//friend class Singleton < T > ;
	static T * i;
protected:
	Singleton(){}
	~Singleton(){};
public:
		static T * instance(){
			return (i) ? i : i = new T;
		}
		static void destruct(){
			if (i){
				delete i;
				i = 0;
			}
		}
};
template<class T> T * Singleton<T>::i = 0;
#endif