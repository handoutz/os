#include <std/cstring.hpp>
#include <system.h>
#include <std/vector.hpp>
#include <syslog.h>
#include <cpp/service.hpp>
#include <cpp/fileservice.hpp>
#include "cppos/services.h"

class ServiceMgr {
public:
    _llnode *m_svcs;
    ServiceMgr() {
        TRACE("svcmgr initialized", "");
    }
    void init() {
        //
        // m_svcs = _llcreate();
        /*FileService *fs = new((FileService *) malloc(sizeof(FileService))) FileService();
        _lladd(m_svcs, fs);
        fs->init();*/
        //m_svcs.push_back(new FileService());
        //Test = new((TestService *) malloc(sizeof(TestService))) TestService();
        //Test->init();
        /*Test = MALLOCATECLASS(TestService);
        Test->init();*/
    }
};

static ServiceMgr *mgr;

extern void initialize_svcs() {
    ServiceMgr *mem = (ServiceMgr *) malloc(sizeof(ServiceMgr));
    mgr = new(mem) ServiceMgr();
    mgr->init();

    //mgr = MALLOCATECLASS(ServiceMgr);
    // mgr = (ServiceMgr *) mem;
    //mgr->init();
}