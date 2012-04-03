template<typename T> class DetectPrevention
{
	typedef char Small;
	class Big { char dummy[2]; };

public:
	static bool Detect()
	{
		return sizeof(DetectImpl<T>(MakeT())) == sizeof(Small);
	}

private:
	template<typename U> static Small DetectImpl(const typename U::self_t);
	template<typename U> static Big DetectImpl(...);

	static T MakeT();
};

/* Non-compiling version
static bool Detect()
{
	return sizeof(DetectImpl<T>(T())) == sizeof(Small);
}
*/