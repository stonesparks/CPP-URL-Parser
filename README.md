# CPP-URL-Parser
Summary:
Program prompts user to input .txt file full of search query links, prints summary in console along with output file parsing out URL options


# Setup
Sample Input file:
![sampei](https://github.com/stonesparks/CPP-URL-Parser/assets/49602745/69bd527e-5cf7-4474-a82b-1f7a3023cb7e)

For simplicity, it would be best to include the input file in the directory of the the main.cpp file, that way, you don't need to specify the file path because it will be relative. 

# Running the program
Once the program reads the file, it will parse the URLs and output a summary of them in the console.

![console](https://github.com/stonesparks/CPP-URL-Parser/assets/49602745/c977586d-aed4-43f4-bd19-eb1b410c2ed6)

# Output File
Finally, the program creats an output.txt file containing all the URLs included in the input file. Each entry includes the search engine used, the query searched, and attempts to parse out all of the options in the URL (this part can have varying results). 

Below is a sample output file:
![outputsample](https://github.com/stonesparks/CPP-URL-Parser/assets/49602745/4b11ed0b-501f-4be8-bd0c-99919644ff35)


# Known Issues

// Please note this code is several years old, I only just recovered it recently and wanted to store it somewhere permanently. That being said, there may be some obvious places that need to be refactored as I've learned a good bit more since coding this up.

* The last entry prints out twice in the output file
* DuckDuckGo query entries are blank in the title section (this was not always true, so maybe the DuckDuckGo Url structure has changed at some point, not sure)

  
