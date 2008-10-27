// PropertyInt.h

#if !defined PropertyInt_HEADER
#define PropertyInt_HEADER

#include "Property.h"

class PropertyInt:public Property{
private:
	wxString title;

public:
	int m_initial_value;
	HeeksObj* m_object;
	void(*m_callbackfunc)(int, HeeksObj*);

	PropertyInt(const wxChar* t, int initial_value, HeeksObj* object, void(*callbackfunc)(int, HeeksObj*) = NULL);
	~PropertyInt();

	// Property's virtual functions
	int get_property_type(){return IntPropertyType;}
	bool property_editable()const{return m_callbackfunc != NULL;}
	Property *MakeACopy(void)const;
	void CallSetFunction()const{ if(m_callbackfunc)(*m_callbackfunc)(m_initial_value, m_object);}
	const wxChar* GetShortString(void)const;
};

#endif
