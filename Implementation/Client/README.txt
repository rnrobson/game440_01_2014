First Time Setup Steps:
	1: Clone the Project
	2: Unzip the Debug.zip
	3: Open the Client.sln
	4: Right Click "ClientAPI" and select Build
	5: Right Click "Client" and set as Startup Project
	6: Right click "Client" and select Build
	7: Run


Adding Resource Assets:
	When adding assets to the Client Project, Ensure you add them to both of the following directories:
		Debug >> Resources
		Client >> Resources

		
Common Errors:
	Problem	
		error LNK1104: cannot open file 'ClientAPI.lib' 	Client
	Explanation
		This error is caused when the Client can not find the ClientAPI.lib within the root project "Debug" Folder
	Solution
		Rebuild "ClientAPI"

	Problem
		x Error in ClientAPI
	Explanation
		Most likely your ClientAPI.lib is out of date
	Solution
		Rebuild "ClientAPI"
		
	Problem:
		x Resource Can Not Be Found
	Explanation
		Your Resources Folder is out of date.
	Solution
		Navigate to Implimentation >> Client >> Client and copy the Resources folder
		Navigate to Implimentation >> Client >> Debug and paste the Resources folder

	