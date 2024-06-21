//
//  dismiss_group_request.cpp
//  proto
//
//  Created by WF Chat on 2017/12/1.
//  Copyright © 2017年 WildFireChat. All rights reserved.
//

#include "set_group_manager.h"
#include "pbc/pbc.h"
    
    namespace mars{
        namespace stn{

            const char* SetGroupManagerRequest::getTypeName() {
                return "SetGroupManagerRequest";
            }
            
            bool SetGroupManagerRequest::unserializeFromPBMsg(struct pbc_rmessage *msg, bool destroy) {
                
                groupId = getString(msg, keyGroupId, 0);
                type = getInt(msg, keyType, 0);
                
                for (int i = 0; i < getSize(msg, keyUserId); i++) {
                    userIds.push_back(getString(msg, keyUserId, i));
                }
                
                for (int i = 0; i < getSize(msg, keyToLine); i++) {
                    toLines.push_back(getInt(msg, keyToLine, i));
                }
                                
                struct pbc_rmessage *notifyContentMsg = getSubMessage(msg, keyNotifyContent, 0);
                notifyContent.unserializeFromPBMsg(notifyContentMsg, false);
                
                
                if(destroy)
                finishRead(msg);
                return true;
            }
            
            void SetGroupManagerRequest::serializeToPBMsg(struct pbc_wmessage* msg) {
                setString(msg, keyGroupId, groupId);
                
                setInt(msg, keyType, type);
                
                for (int i = 0; i < userIds.size(); i++) {
                    setString(msg, keyUserId, userIds.at(i));
                }
                
                for (int i = 0; i < toLines.size(); i++) {
                    setInt(msg, keyToLine, toLines.at(i));
                }
                
                struct pbc_wmessage *notifyContentMsg = setSubMessaage(msg, keyNotifyContent);
                notifyContent.serializeToPBMsg(notifyContentMsg);
            }
        }
    }
