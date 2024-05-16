class vectors
{	 
	private:
		double x;
		double y;
		double x1;
		double y1;
		double x2;
		double y2;
		double x3;
		double y3;
		double x4;
		double y4;
	public:
		vectors();
		~vectors();
		void vec1(double x, double y);
		void vec2(double x, double y, double x1, double y2);
		void vec3(double x, double y, double x2, double y2, double x3, double y3);
		void vec4(double x, double y, double x1, double x2, double y2, double x3, double y3, double x4, double y4);
};	

void vectors::vec1(double x, double y)
{
	this->x = x;
	this->y = y;
}

void vectors::vec2(double x, double y, double x1, double y2)
{
	this->x = x;
	this->y = y;
	this->x1 = x1;
	this->y2 = y2;
}

void vectors::vec3(double x, double y, double x2, double y2, double x3, double y3)
{
	this->x = x;
	this->y = y;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
}

void vectors::vec4(double x, double y, double x1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	this->x = x;
	this->y = y;
	this->x1 = x1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;
}
