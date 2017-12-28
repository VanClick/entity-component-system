#pragma once

class IInterface
{
public:

	template<typename T>
	bool Query(T **result)
	{
		return Query(T::IID,(IInterface **)result);
	}

	virtual bool Query(int id, IInterface **result) = 0;

};
