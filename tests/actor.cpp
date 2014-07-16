#include "memepool-tests.h"
#include "memepool.h"

TEST(InitTerminate, Actor, 0.0f,
     // initialisation
     {
     m_data.actor = 0;
     },
     // cleanup
     {
     memeTerminateActor(&m_data.actor);
     },
     // test
     {
     ASSERT(memeInitActor(&m_data.actor) == MP_SUCCESS);
      ASSERT(m_data.actor != 0);
     ASSERT(memeTerminateActor(&m_data.actor) == MP_SUCCESS);
      ASSERT(m_data.actor == 0)
     },
     // data
     {
     memeActor* actor;
     }
    );

TEST(AddConstruct, Actor, 0.0f,
     // initialisation
     {
     memeInitActor(&m_data.actor);
     memeInitConstruct(&m_data.construct);
     },
     // cleanup
     {
     memeTerminateActor(&m_data.actor);
     memeTerminateConstruct(&m_data.construct);
     },
     // test
     {
        ASSERT(memeActorAddConstruct(m_data.actor, m_data.construct) == MP_SUCCESS);
     },
     // data
     {
     memeActor* actor;
     memeConstruct* construct;
     }
    );