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
		string outputHttpUrl = "http://www.hotelcosmos.ru:80/restaurant";
		string outputHttpsUrl = "https://www.hotelcosmos.ru:443/restaurant";

		string domain = "www.hotelcosmos.ru";
		string document = "/restaurant";
		Protocol https = Protocol::HTTPS;
		Protocol http = Protocol::HTTP;

		WHEN("Save url without http protocol")
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
		string inputHttpUrl = "http://www.hotelcosmos.ru:80/restaurant";
		string inputHttpsUrl = "https://www.hotelcosmos.ru:443/restaurant";
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
	string inputHttpUrl = "http://www.hotelcosmos.ru:80/restaurant";
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
	string inputHttpsUrl = "https://www.hotelcosmos.ru:443/restaurant";
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

TEST_CASE("Http url without port")
{
	string inputHttpUrl = "http://www.hotelcosmos.ru/restaurant";
	string outputHttpUrl = "http://www.hotelcosmos.ru:80/restaurant";
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
			CHECK(url.GetUrl() == outputHttpUrl);
		}
	}
}

TEST_CASE("Https url without port")
{
	string inputHttpUrl = "https://www.hotelcosmos.ru/restaurant";
	string outputHttpUrl = "https://www.hotelcosmos.ru:443/restaurant";
	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol http = Protocol::HTTPS;
	unsigned short httpPort = 443;

	WHEN("Save https url")
	{
		CHttpUrl url(inputHttpUrl);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == http);
			CHECK(url.GetPort() == httpPort);
			CHECK(url.GetUrl() == outputHttpUrl);
		}
	}
}

TEST_CASE("Wrong https url")
{
	string inputHttpsUrlWithoutPort = "httts://www.hotelcosmos.ru/restaurant";

	WHEN("Save https url")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(inputHttpsUrlWithoutPort), CUrlParsingError);
		}
	}
}

TEST_CASE("https with boundary values port")
{
	string inputHttpsUrlWithPort0 = "https://www.hotelcosmos.ru:0/restaurant";
	string inputHttpsUrlWithPort1 = "https://www.hotelcosmos.ru:1/restaurant";
	string inputHttpsUrlWithPort65535 = "https://www.hotelcosmos.ru:65535/restaurant";
	string inputHttpsUrlWithPort65536 = "https://www.hotelcosmos.ru:65536/restaurant";

	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol https = Protocol::HTTPS;
	unsigned short httpsPort1 = 1;
	unsigned short httpsPort65535 = 65535;

	WHEN("Save https url with 0 port")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(inputHttpsUrlWithPort0), CUrlParsingError);
		}
	}

	WHEN("Save https url with 65536 port")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(inputHttpsUrlWithPort65536), CUrlParsingError);
		}
	}

	WHEN("Save https url with port 1")
	{
		CHttpUrl url(inputHttpsUrlWithPort1);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == https);
			CHECK(url.GetPort() == httpsPort1);
			CHECK(url.GetUrl() == inputHttpsUrlWithPort1);
		}
	}

	WHEN("Save https url with port 65535")
	{
		CHttpUrl url(inputHttpsUrlWithPort65535);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == https);
			CHECK(url.GetPort() == httpsPort65535);
			CHECK(url.GetUrl() == inputHttpsUrlWithPort65535);
		}
	}
}

TEST_CASE("Save url by parameters with zero port")
{
	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol https = Protocol::HTTPS;
	unsigned short port = 0;

	WHEN("Save https url with 0 port")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(domain, document, https, port), CUrlParsingError);
		}
	}
}

TEST_CASE("Save url by parameters with wrong port")
{
	string domain = "www.hotelcosmos.ru";
	string document = "/restaurant";
	Protocol https = Protocol::HTTPS;
	unsigned short port = 0;

	WHEN("Save https url with 0 port")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(domain, document, https, port), CUrlParsingError);
		}
	}
}

TEST_CASE("Save https url without port and document")
{
	string inputHttpsUrl = "https://www.hotelcosmos.ru";
	string outputHttpsUrl = "https://www.hotelcosmos.ru:443";
	string domain = "www.hotelcosmos.ru";
	string document = "";
	Protocol https = Protocol::HTTPS;
	unsigned short port = 443;

	WHEN("Save https url")
	{
		CHttpUrl url(inputHttpsUrl);

		THEN("Can get url parameters")
		{
			CHECK(url.GetDomain() == domain);
			CHECK(url.GetDocument() == document);
			CHECK(url.GetProtocol() == https);
			CHECK(url.GetPort() == port);
			CHECK(url.GetUrl() == outputHttpsUrl);
		}
	}
}

TEST_CASE("Save https url without domain")
{
	string inputHttpsUrl = "https:///restaurant:65535";

	WHEN("Save https url with 0 port")
	{
		THEN("Can get error message")
		{
			CHECK_THROWS_AS(CHttpUrl(inputHttpsUrl), CUrlParsingError);
		}
	}
}
