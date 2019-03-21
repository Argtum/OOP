#include "pch.h"
#include "HtmlDecoder.h"

int main()
{
	string html;

	cout << "Enter HTML string: ";
	cin >> html;

	HtmlDecode(html);

	cout << html << endl;

	return 0;
}
