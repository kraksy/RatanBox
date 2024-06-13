class guiElement {
public:
  guiElement();
  ~guiElement();

  typedef struct Vec2;
  typedef struct Element;
  typedef struct Color;
};

guiElement::guiElement() {}

guiElement::~guiElement() {}

typedef struct Color {
  float r;
  float g;
  float b;
  float a;
} Color;

typedef struct Vec2 {
  float x;
  float y;
} Vec2;

typedef struct Element {
  Vec2 position;
  Vec2 size;
  Color color;
} Element;
