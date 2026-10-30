

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
		std::function<void(T)> tlfunc;
		std::uint16_t begin;
		std::uint16_t end;
		std::uint16_t total;
		std::uint8_t active;
	};
	T data;
	std::vector<tunnelInfo> tunnel;


public:
	Flow(T fT) : data(fT) {}

	void update(const std::function<T(T)> &uF) {
		this->data = uF(this->data);
		std::size_t ts =this->tunnel.size();
		for(std::size_t idx=0; idx <ts; idx++) {
			auto &tls =  this->tunnel[idx];
			if(!tls.active || (tls.begin > ts)) {
				continue;
			}

			if((tls.begin)==ts) {
				tls.tlfunc(this->data);
				tls.total=1;
				tls.active=1;
			} else if(tls.total==tls.end) {
				tls.active=(std::uint8_t)(0);
			} else {
				tls.tlfunc(this->data);
				tls.total=(std::uint16_t)(tls.total+1);
				tls.active=tls.active;
			}
		}
	}
	void collect(const std::function<void(T)> &cF, std::uint16_t bg=0, std::uint16_t end=0) {
		cF(this->data);
		tunnelInfo aF= {
			cF, bg, end,
			(std::uint16_t)(1), (std::uint8_t)(1)
		};
		this->tunnel.push_back(aF);
	}
};
}
#endif

