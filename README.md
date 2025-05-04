# AI_API
Using Github API to access different AI models.
Accessable AI models:
-Meta-Llama-3-8B-Instruct
-Microsoft/Phi-4
-ChapGpt 4o

Required Libraries:
cpr/cpr.h
nlohmann/json.hpp
This libraries can be installed via vcpkg.To install them simply run;
vcpkg install cpr nlohmann-json
Important Notes:
1-Linking Libraries:
Make sure to link the installed libraries correctly in your project settings. If you're using Visual Studio, check the 'Additional Dependencies' in the project properties to ensure the libraries are linked properly.
2- .dll files:
Make Sure that provided .dll files are in the same folder as .exe file.

How to Get API token:
https://github.com/marketplace/models from this URL, steps are;
1- Just Select a Random Model
2- Right Top Use this Model
3- Get Developer Key
And Now You Have a Token 
Code Uses Github API no need different Tokens for Different Models




