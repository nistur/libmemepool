#include "memepool-tests.h"
#include "memepool.h"

TEST(InitTerminate, Construct, 0.0f,
     // initialisation
     {
     m_data.construct = 0;
     },
     // cleanup
     {
     memeTerminateConstruct(&m_data.construct);
     },
     // test
     {
     ASSERT(memeInitConstruct(&m_data.construct) == MP_SUCCESS);
      ASSERT(m_data.construct != 0);
     ASSERT(memeTerminateConstruct(&m_data.construct) == MP_SUCCESS);
      ASSERT(m_data.construct == 0)
     },
     // data
     {
     memeConstruct* construct;
     }
    );

TEST(SimpleTerms, Construct, 0.0f,
     // initialisation
     {
     m_data.construct = 0;
     memeInitConstruct(&m_data.construct);
     },
     // cleanup
     {
     memeTerminateConstruct(&m_data.construct);
     },
     // test
     {
        ASSERT(memeConstructAddTerms(m_data.construct, "[SUBJECT]", "is", "[ADJECTIVE]", 0) == MP_SUCCESS);
     },
     // data
     {
     memeConstruct* construct;
     }
    );

TEST(Evaluate, Construct, 0.0f,
     // initialisation
     {
     m_data.construct = 0;
     memeInitConstruct(&m_data.construct);
     memeInitTerm(&m_data.terms[0]);
     memeInitTerm(&m_data.terms[1]);
     memeTermSetClass(m_data.terms[0], "[SUBJECT]");
     memeTermSetData(m_data.terms[0], "the banana");
     memeTermSetClass(m_data.terms[1], "[ADJECTIVE]");
     memeTermSetData(m_data.terms[1], "tasty");
     memeConstructAddTerms(m_data.construct, "[SUBJECT]", "is", "[ADJECTIVE]", 0);
     },
     // cleanup
     {
     memeTerminateConstruct(&m_data.construct);
     },
     // test
     {
        ASSERT(memeConstructEvaluate(m_data.construct, m_data.terms, 2, &m_data.output) == MP_SUCCESS);

        // This should be tested in the Term group, not here
        memeTermGetData(m_data.output[0], m_data.buffer, 256);

        ASSERT(strcmp(m_data.buffer, "The banana is tasty.") == 0);


     },
     // data
     {
     memeConstruct* construct;
     memeTerm*      terms[2];
     memeTermList   output;
     char           buffer[256];
     }
    );
