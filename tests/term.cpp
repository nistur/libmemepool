#include "memepool-tests.h"
#include "memepool.h"

TEST(InitTerminate, Term, 0.0f,
        // initialisation
        {
            m_data.term = 0;
        },
        // cleanup
        {
            memeTerminateTerm(&m_data.term);
        },
        // test
        {
            ASSERT(memeInitTerm(&m_data.term) == MP_SUCCESS);
            ASSERT(m_data.term != 0);
            ASSERT(memeTerminateTerm(&m_data.term) == MP_SUCCESS);
            ASSERT(m_data.term == 0)
        },
        // data
        {
            memeTerm* term;
        }
    );
