

#ifndef Flow_H
#define Flow_H

#include <functional>
#include <vector>
#include <cstdint>
#include <algorithm>

namespace Tunnel {
template <typename T>
class Flow {
private:
	struct tunnelInfo {
		std::function<void(const T&)> tlfunc;
		std::uint16_t begin;
		std::uint16_t end;
		std::uint16_t total;
		std::uint8_t active;
	};
	T data;
	std::uint16_t ctunnel =0;
	std::vector<tunnelInfo> tunnel;
public:
	Flow(T fT) : data(fT) {}


	void update(const std::function<T(const T&)> &uF) {
		this->data = std::move(uF(this->data));
		std::size_t ts =this->tunnel.size();
		for(std::size_t idx=0; idx <ts; idx++) {
			auto &tls =  this->tunnel[idx];
			if(!tls.active ) {
				continue;
			}

			if((tls.begin) > this->ctunnel) {
				continue;
			}
			if(tls.end != 0 && tls.total>=tls.end) {
				tls.active=0;
			} else {
				tls.tlfunc(this->data);
				tls.total=(std::uint16_t)(tls.total+1);
				tls.active=1;
			}
		}
	}
	void collect(const std::function<void(const T&)> &cF, std::uint16_t bg=0, std::uint16_t end=0) {

		tunnelInfo aF{cF, bg, end, 0,1};

		/*
		if(((std::uint16_t)(this->tunnel.size()))>= bg){
		    //cF(this->data);
		    aF.total = 1; aF.active = 1;
		    }else{
		      aF.total = 0; aF.active = 1;
		    }
		    */

		this->ctunnel = this->tunnel.size();
		this->tunnel.push_back(aF);

	}

};
}
#endif

