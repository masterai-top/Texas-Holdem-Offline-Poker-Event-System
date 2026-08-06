#include "Comm/ITableGame.h"
#include "common/macros.h"
#include "common/nndef.h"
#include "utils/tarslog.h"
#include "gameroot.h"
#include "logic/roomlogic/core/userlefttable.h"
#include "logic/gamelogic/core/checkbegin.h"
#include "context/context.h"
#include "process/process.h"
#include "message/sendroommessage.h"
#include "logic/clientlogic/core/tokenbet.h"
#include "logic/gamelogic/core/endtimer.h"
#include "config/gameconfig.h"
#include "suoha.pb.h"

using namespace nndef;

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {

            using namespace RoomSo;
            using namespace context;
            using namespace process;
            using namespace gamelogic;
            using namespace message;
            using namespace config;
            using namespace clientlogic;
            int UserLeftTable(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                TGAME_UserLeftTable const *nnrs = static_cast<TGAME_UserLeftTable const *>(p);
                User *user = root->con->getUserByUid(nnrs->lPlayerID);

                if (nnrs == NULL || user == NULL)
                {
                    DLOG_TRACE("roomid:" << root->roomid()<< ", uid: "<< nnrs->lPlayerID);
                    return 0;
                }        
                if (user->isLeft())
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ", " << " user left user uid: " << nnrs->lPlayerID << ", process: "<< root->pro->getProcess());
                    return 0;
                }

                user->setLeft(true);
                DLOG_TRACE("roomid:" << root->roomid() << ", " << " user left user uid: " << nnrs->lPlayerID << ", process: "<< root->pro->getProcess());

                //游戏没有开始
                if(root->pro->getProcess() == nil_nnstate)
                {
                    //剔除
                    if(nnrs->iType == 1)
                    {
                        // EndTimer(NN_XTIME_BUBI, root, false);

                        TGAME_Stand tmm;
                        tmm.lPlayerID = nnrs->lPlayerID;
                        tmm.iType = 0;
                        tmm.bBuyIn = false;
                        sendRoomMessage<TGAME_Stand>(TGAME_Stand_E, tmm, root);
                    }
                    root->con->delUser(nnrs->lPlayerID);
                }

                // if (!user->isRobot())
                // {
                //     //变更货币
                //     TGAME_PlayerScoreChange tmm;
                //     tmm.info.buyInNum = 0;
                //     tmm.info.winNum = 0;
                //     tmm.info.buyInCount = 0;
                //     tmm.aiInfo.iAiGameRound = 0;
                //     tmm.aiInfo.iAiGamePoint = 0;
                //     tmm.iNowRound = 0;
                //     tmm.changeType = 2;
                //     tmm.changePoint.insert(std::make_pair(user->getUid(), user->getSHWealth()));
                //     sendRoomMessage<TGAME_PlayerScoreChange>(TGAME_PlayerScoreChange_E, tmm, root);
                //     DLOG_TRACE("roomid:" << root->roomid() << ", user left uid: " << user->getUid() << ", Coin: " << user->getSHWealth());
                //     user->setSHWealth(0);
                // }
                
                // //游戏中
                // if (!root->con->getGameCal() && root->pro->getProcess() >= NN_STATE_GAME_BEGIN )
                // {
                //     cid_t tokencid = root->con->getTokenCid();
                //     if (tokencid == user->getCid())//主动弃牌处理
                //     {
                //         XGameSHProto::SH_msg2csTokenBet shcm;
                //         shcm.set_icid(tokencid);
                //         shcm.set_iact(NN_ACT_FOLD);
                //         shcm.set_lbetscore(0);
                //         vector<char> vecOutBuffer;
                //         pbTobuffer(shcm, vecOutBuffer);
                //         clientlogic::TokenBet(user->getUid(), vecOutBuffer, root, false, true);
                //     }
                //     else
                //     {
                //         //当前打牌活跃人数
                //         std::vector<int> vCidActive;
                //         std::map<cid_t, User> const &usermap = root->con->getUserMap();
                //         for (auto it = usermap.begin(); it != usermap.end(); it++)
                //         {
                //             User *user = root->con->getUserByCid(it->first);
                //             if(user && !user->isMidSit() && !user->isFold() && !user->isAllIn() && !user->isLeft())
                //             {
                //                 vCidActive.push_back(it->first);
                //             }
                //         }
                        
                //         if(vCidActive.size() == 1)
                //         {
                //             root->con->setNormalEnd(false);
                //             root->pro->turnProcess(NN_STATE_GAME_END);    
                //         }
                //         DLOG_TRACE("roomid:" << root->roomid() << ", vCidActive: " << vCidActive.size() );
                //     }
                // }
                // else
                // {
                //     EndTimer(NN_XTIME_BUBI, root, false);
                //     root->con->delUser(nnrs->lPlayerID);
                // }
                __CATCH__
                PERFSTATS_EXIT();
                return 0;
            }
        }
    }
}
