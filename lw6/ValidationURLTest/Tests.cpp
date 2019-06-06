#include "pch.h"
#include "lw6/ValidationURL/CHttpUrl.h"

using namespace std;

TEST_CASE("Make url by parameters without port")
{
	GIVEN("URL parameters")
	{
		string domain = "www.hotelcosmos.ru";
		string document = "/restaurant";
		Protocol protocol = Protocol::HTTPS;

		WHEN("create url")
		{
			CHttpUrl url(domain, document);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == Protocol::HTTP);
			}
		}
	}
}
