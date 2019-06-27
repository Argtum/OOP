#include "pch.h"
#include "lw6/ValidationURL/CHttpUrl.h"
#include "lw6/ValidationURL/CUrlParsingError.h"

using namespace std;

TEST_CASE("Save url by parameters without port")
{
	GIVEN("URL parameters")
	{
		string inputHttpUrl = "http://www.hotelcosmos.ru/restaurant";
		string inputHttpsUrl = "https://www.hotelcosmos.ru/restaurant";
		string outputHttpUrl = "http://www.hotelcosmos.ru/restaurant:80";
		string outputHttpsUrl = "https://www.hotelcosmos.ru/restaurant:443";

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
				CHECK(url.GetUrl() == outputHttpUrl);
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
				CHECK(url.GetUrl() == outputHttpUrl);
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
				CHECK(url.GetUrl() == outputHttpsUrl);
			}
		}
	}
}

TEST_CASE("Save url by parameters with port")
{
	GIVEN("URL parameters")
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
			CHttpUrl url(domain, document, http, httpPort);

			THEN("Can get url parameters")
			{
				CHECK(url.GetDomain() == domain);
				CHECK(url.GetDocument() == document);
				CHECK(url.GetProtocol() == http);
				CHECK(url.GetPort() == httpPort);
				CHECK(url.GetUrl() == inputHttpUrl);
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
				CHECK(url.GetUrl() == inputHttpsUrl);
			}
		}
	}
}

TEST_CASE("ToLowercase must translate text to lower case")
{
	string input = "hTTP";
	string input1 = "Http";
	string input2 = "http";

	string httpResult = "http";

	ToLowercase(input);
	ToLowercase(input1);
	ToLowercase(input2);

	CHECK(input == httpResult);
	CHECK(input1 == httpResult);
	CHECK(input2 == httpResult);
}

TEST_CASE("Http url")
{
	string inputHttpUrl = "http://www.hotelcosmos.ru/restaurant:80";
	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol http = Protocol::HTTP;
	unsigned short httpPort = 80;

	WHEN("Save http url")
	{
		CHttpUrl url(inputHttpUrl);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == http);
			CHECK(url.GetPort() == httpPort);
			CHECK(url.GetUrl() == inputHttpUrl);
		}
	}
}

TEST_CASE("Https url")
{
	string inputHttpsUrl = "https://www.hotelcosmos.ru/restaurant:443";
	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol https = Protocol::HTTPS;
	unsigned short httpsPort = 443;

	WHEN("Save https url")
	{
		CHttpUrl url(inputHttpsUrl);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == https);
			CHECK(url.GetPort() == httpsPort);
			CHECK(url.GetUrl() == inputHttpsUrl);
		}
	}
}

TEST_CASE("Https url without port")
{
	string inputHttpsUrlWithoutPort = "https//www.hotelcosmos.ru/restaurant";

	WHEN("Save https url")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(inputHttpsUrlWithoutPort), CUrlParsingError);
		}
	}
}
