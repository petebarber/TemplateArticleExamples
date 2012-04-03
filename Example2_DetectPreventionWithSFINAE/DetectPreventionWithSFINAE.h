class DetectPreventionWithSFINAE
{
public:
	template<typename U>
	static bool Detect(const typename U::self_t)
	{ 
		return true;	
	}

	template<typename U>
	static bool Detect(...)
	{ 
		return false;	
	}
};