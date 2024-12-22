#ifdef GLLITE_SHARED
	#ifdef GLLITE_EXPORTS
		#define GLLITE_API __declspec(dllexport)  // Exporting symbols when building the DLL
	#else
		#define GLLITE_API __declspec(dllimport)  // Importing symbols when using the DLL
	#endif
#else
	#define GLLITE_API
#endif
