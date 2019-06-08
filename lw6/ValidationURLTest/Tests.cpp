#include "pch.h"
#include "lw6/ValidationURL/CHttpUrl.h"

using namespace std;

TEST_CASE("Save url by parameters without port")
{
	GIVEN("URL parameters")
	{
		string domain = "www.hotelcosmos.ru";
		string document = "/restaurant";
		Protocol https = Protocol::HTTPS;
		Protocol http = Protocol::HTTP;

		WHEN("Save url without protocol")
		{
			CHttpUrl url(domain, document);

			THEN("Can get url parameters with HTTP protocol")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == http);
			}
		}

		WHEN("Save url with HTTP protocol")
		{
			CHttpUrl url(domain, document, http);

			THEN("Can get url parameters with HTTP protocol")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == http);
			}
		}

		WHEN("Save url with HTTPS protocol")
		{
			CHttpUrl url(domain, document, https);

			THEN("Can get url parameters with HTTPS protocol")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == https);
			}
		}
	}
}

TEST_CASE("Save url by parameters with port")
{
	GIVEN("URL parameters")
	{
		string domain = "www.hotelcosmos.ru";
		string document = "/restaurant";
		Protocol https = Protocol::HTTPS;
		Protocol http = Protocol::HTTP;
		unsigned short httpPort = 80;
		unsigned short httpsPort = 443;

		WHEN("Save http url")
		{
			CHttpUrl url(domain, document, http, httpPort);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == http);
				CHECK(url.GetPort() == httpPort);
			}
		}

		WHEN("Save https url")
		{
			CHttpUrl url(domain, document, https, httpsPort);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == https);
				CHECK(url.GetPort() == httpsPort);
			}
		}
	}
}

TEST_CASE("Save the url")
{
	GIVEN("URL")
	{
		string inputHttpUrl = "http://www.hotelcosmos.ru/restaurant:80";
		string inputHttpsUrl = "https://www.hotelcosmos.ru/restaurant:443";
		string domain = "www.hotelcosmos.ru";
		string document = "/restaurant";
		Protocol https = Protocol::HTTPS;
		Protocol http = Protocol::HTTP;
		unsigned short httpPort = 80;
		unsigned short httpsPort = 443;

		WHEN("Save http url")
		{
			CHttpUrl url(inputHttpUrl);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == http);
				CHECK(url.GetPort() == httpPort);
			}
		}

		WHEN("Save https url")
		{
			CHttpUrl url(inputHttpsUrl);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == https);
				CHECK(url.GetPort() == httpsPort);
			}
		}
	}
}
