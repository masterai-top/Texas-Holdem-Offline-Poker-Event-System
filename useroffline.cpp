#include "common/macros.h"
#include "gameroot.h"
#include "logic/roomlogic/core/useroffline.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            void UserOffline(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                //DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"UserOffline.");

                using namespace RoomSo;
                using namespace context;

               

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
