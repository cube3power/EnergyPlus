#ifndef IdfParserFixture_hh_INCLUDED
#define IdfParserFixture_hh_INCLUDED

// Google Test Headers
#include <gtest/gtest.h>

// EnergyPlus Headers
#include <EnergyPlus/DataStringGlobals.hh>

#include "../TestHelpers/IdfParser.hh"

namespace EnergyPlus {

	class IdfParserFixture : public testing::Test
	{
	protected:
		static void SetUpTestCase() { }
		static void TearDownTestCase() { }

		virtual void SetUp() { }

		virtual void TearDown() { }

		// This function creates a string based on a vector of string inputs that is delimited by DataStringGlobals::NL by default, but any 
		// delimiter can be passed in to this funciton. This allows for cross platform output string comparisons.
		std::string delimited_string( std::vector<std::string> const & strings, std::string const & delimiter = DataStringGlobals::NL ) {
			std::unique_ptr<std::ostringstream> compare_text(new std::ostringstream);
			for( auto const & str : strings ) {
				* compare_text << str << delimiter;
			}
			return compare_text->str();
		}

		void eat_whitespace( std::string const & idf, size_t & index ) {
			IdfParser parser;
			parser.eat_whitespace( idf, index );
		}

		void eat_comment( std::string const & idf, size_t & index ) {
			IdfParser parser;
			parser.eat_comment( idf, index );
		}

		std::string parse_string( std::string const & idf, size_t & index, bool & success) {
			IdfParser parser;
			return parser.parse_string( idf, index, success );
		}

		std::string parse_value( std::string const & idf, size_t & index, bool & success) {
			IdfParser parser;
			return parser.parse_value( idf, index, success );
		}

		IdfParser::Token look_ahead( std::string const & idf, size_t index)
		{
			IdfParser parser;
			return parser.look_ahead( idf, index );
		}

		IdfParser::Token next_token( std::string const & idf, size_t & index)
		{
			IdfParser parser;
			return parser.next_token( idf, index );
		}

		std::vector< std::vector< std::string > > parse_idf( std::string const & idf, size_t & index, bool & success ) {
			IdfParser parser;
			return parser.parse_idf( idf, index, success );
		}

		std::vector< std::string > parse_object( std::string const & idf, size_t & index, bool & success ) {
			IdfParser parser;
			return parser.parse_object( idf, index, success );
		}
		
	};

	typedef IdfParserFixture IdfParserDeathTestFixture;
}

#endif
