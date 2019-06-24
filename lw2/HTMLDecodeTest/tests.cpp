#include "pch.h"
#include "lw2/HTMLDecode/HtmlDecoder.h"

using namespace std;

TEST_CASE("ReplaceHtmlEntity - function should convert the html entity into characters")
{
	string inputStr, outputStr, emptyString, htmlEntity;

	inputStr = "&quot;Meow&quot;";
	outputStr = "\"Meow\"";
	emptyString = "";
	htmlEntity = "&quot;";

	CHECK(outputStr == GetReplaceHtmlEntity(inputStr, htmlEntity));
	CHECK(emptyString == GetReplaceHtmlEntity(emptyString, htmlEntity));
}

TEST_CASE("HtmlDecode - funcrion should return new string without HTML entitys")
{
	string inputStr, outputStr, emptyString;

	inputStr = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	outputStr = "Cat <says> \"Meow\". M&M's";
	emptyString = "";

	CHECK(outputStr == GetHtmlDecode(inputStr));
	CHECK(emptyString == GetHtmlDecode(emptyString));
}
