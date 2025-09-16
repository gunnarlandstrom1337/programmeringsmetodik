#include "dynbuffer.h"
#include <algorithm>

// SRP SINGLE RESPONSIBILITY PRINCIPLE


dynbuffer::dynbuffer(buffer src) :data(src)
{
}

void dynbuffer::push_back(int e)
{
	buffer new_data(data.size() + 1);
	if (sz > capacity()) {
		resize();
	}

	std::copy(data.begin(), data.end(), new_data.begin());
	new.data.back() = e;

	data = std::move(new_data); //väljer konstruerare
}

void dynbuffer::resize() {
	buffer new_data(data.size() + 16);
	std::copy(data.begin(), data.begin() + sz, new_data.begin());
	data = std::move(new_data);
}


int& dynbuffer::front() {



}

int& dynbuffer::back() {

}