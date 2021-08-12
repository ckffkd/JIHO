#pragma once

template<typename T>
void Safe_Delete(T& _obj)
{
	delete (_obj);
	_obj = nullptr;
}
#define SAFE_DELETE(type) Safe_Delete(type)