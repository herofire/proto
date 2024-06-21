//
//  dismiss_group_request.hpp
//  proto
//
//  Created by WF Chat on 2017/12/1.
//  Copyright © 2017年 WildFireChat. All rights reserved.
//

#ifndef set_group_manager_request_hpp
#define set_group_manager_request_hpp

#include <stdio.h>
#include <string>
#include "pbbase.h"
#include <vector>
#include "messagecontent.h"

struct pbc_rmessage;
struct pbc_wmessage;

namespace mars{
    namespace stn{
        class PBBase;
        
        
        class SetGroupManagerRequest : public PBBase{
        protected:
            virtual const char* getTypeName();
        public:
            SetGroupManagerRequest() {}
            virtual ~SetGroupManagerRequest() {}
            virtual bool unserializeFromPBMsg(struct pbc_rmessage *msg, bool destroy);
            virtual void serializeToPBMsg(struct pbc_wmessage* msg);
            
            std::string groupId;
            int type;
            std::vector<std::string> userIds;
            std::vector<int> toLines;
            MessageContent notifyContent;

        };
    }
}
#endif /* set_group_manager_request_hpp */

