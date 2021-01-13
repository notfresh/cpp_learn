//
// Created by zxzx on 2021/1/8.
//

#include <zxlib/print.h>
int main(int argc, char** argv) {
	cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
							   cpr::Authentication{"user", "pass"},
							   cpr::Parameters{{"anon", "true"}, {"key", "value"}});
//	r.status_code;                  // 200
//	r.header["content-type"];       // application/json; charset=utf-8
//	r.text;                         // JSON text string
	print(r.status_code)
}