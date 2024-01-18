#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

namespace helper {
	// finds query from url
	void query_find(string url, string& query) {
		int a = url.find_first_of("q=") + 2;
		int b = url.find("&");
		int l = (b - a);
		query = url.substr(a, l);
		replace(query.begin(), query.end(), '+', ' ');
	}    // finds site from url
	void site(string url, string& site_name) {
		int a = url.find("//") + 2;
		int b = url.find(".com");
		int l = (b - a);
		site_name = url.substr(a, l);
		string d = "www.";
		int e = site_name.find("www.");
		if (site_name.find(d) != string::npos) {
			site_name.erase(e, 4);
		}
	}    // finds url length
	void urllength(string url, int& url_length) {
		url_length = url.length();
	}    // fnds query length 
	void query_length(string query, int& query_length) {
		query_length = query_length + query.length();

	}
	// finds options from url
	vector<string> options(const string& url)
	{
		vector<string> result;
		auto a = url.find("?");
		if (a == string::npos) return result;

		auto b = url.find("&");
		if (b == string::npos)
		{
			result.push_back(url.substr(a + 1, string::npos));
			return result;
		}
		result.push_back(url.substr(a + 1, b - a - 1));
		do
		{
			a = b;
			b = url.find("&", a + 1);
			result.push_back(url.substr(a + 1, b - a - 1));
		} while (b != string::npos);
		return result;

	}
}







namespace interface {
	// prints overall stats from urls into console
	void final_stats(int urlcount, int url_length_average, int query_length_average, int average_options, string openfile) {
		int file_name_length = openfile.length();
		int line_length = (file_name_length + 17);
		cout << "Statistics for: " << openfile << endl;
		cout << setfill('~') << setw(line_length) << " " << endl;
		setfill(' ');
		cout << "Number of Queries: " << urlcount << endl;
		cout << "Average length of URL: " << url_length_average << endl;
		cout << "Average Length of Query String: " << query_length_average << endl;
		cout << "Average number of options: " << average_options << endl;
	}
	// prints stats from each url into one file
	void final_output(string url, string query, string site_name, ofstream& output, int& option_count) {
		output << site_name << ": " << query << endl;
		int line_length = site_name.length() + query.length() + 2;
		output << setfill('~') << setw(line_length) << " " << endl;
		setfill(' ');
		output << "URL: " << url << endl;
		option_count = 0;
		auto vec = helper::options(url);
		for (const auto& i : vec) {
			option_count++;
			output << "Option " << option_count << ": " << i << endl;
		}

		output << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}

}





int main() {
	string url, query;
	int urlcount = 0, url_length, url_length_average = 0;
	int option_count = 0, total_options = 0, average_options;
	int query_length = 0;
	string site_name, openfile;
	ifstream input; ofstream output;
	output.open("output.txt");
	while (1) {
		cout << "Enter a search query file to open: ";
		cin >> openfile;
		input.open(openfile);

		if (input.is_open())
			break;
	}
	// main loop reading file contents
	while (!input.eof()) {
		input >> url;
		helper::site(url, site_name);
		helper::query_find(url, query);
		helper::urllength(url, url_length);
		helper::query_length(query, query_length);
		url_length_average = url_length_average + url_length;
		urlcount++;
		interface::final_output(url, query, site_name, output, option_count);
		total_options = total_options + option_count;
	}

	average_options = total_options / urlcount;

	int query_length_average = query_length / urlcount;
	url_length_average = url_length_average / urlcount;

	interface::final_stats(urlcount, url_length_average, query_length_average, average_options, openfile);

	output.close();


	return 0;

}

