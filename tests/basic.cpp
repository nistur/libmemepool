#include "memepool-tests.h"
#include "memepool.h"

TEST(InitTerminate, Basic, 0.0f,
     // initialisation
     {
	 m_data.context = 0;
     },
     // cleanup
     {
	 memeTerminateContext(&m_data.context);
     },
     // test
     {
	 ASSERT(memeInitContext(&m_data.context) == MP_SUCCESS);
      ASSERT(m_data.context != 0);
	 ASSERT(memeTerminateContext(&m_data.context) == MP_SUCCESS);
      ASSERT(m_data.context == 0)
     },
     // data
     {
	 memeContext* context;
     }
    );
