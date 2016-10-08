#include <std/cstring.hpp>
#include <system.h>
#include <std/vector.hpp>
#include <syslog.h>
#include "cppos/services.h"

#define dolog(name, fmt, ...) log_service(name->raw(), fmt, __VA_ARGS__)

class TestService {
public:
    std::str *m_name;
    STRING name() const { return m_name->raw(); }
    TestService() {
        m_name = new std::str("tester");
    }
    ~TestService() {}
    void init() {
        dolog(m_name, "lol my name is %s", m_name->raw());
    }
};

class ServiceMgr {
public:
    ServiceMgr() {
        TRACE("svcmgr initialized", "");
    }
    TestService *Test;
    void init() {
        Test = new((TestService *) malloc(sizeof(TestService))) TestService();
        Test->init();
        /*Test = MALLOCATECLASS(TestService);
        Test->init();*/
    }
};

static ServiceMgr *mgr;

extern void initialize_svcs() {
    ServiceMgr *mem = (ServiceMgr *) malloc(sizeof(ServiceMgr));
    mgr = new(mem) ServiceMgr();
    // mgr = (ServiceMgr *) mem;
    mgr->init();
}