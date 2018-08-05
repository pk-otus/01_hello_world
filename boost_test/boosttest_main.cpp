#include "../VersionControl/version_control.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(boost_version_valid)
{
	BOOST_CHECK(VersionControl::GetVersion() > 0 );
}

BOOST_AUTO_TEST_SUITE_END()
