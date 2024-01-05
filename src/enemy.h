class enemy 
{

    String name;
    int health;
    int maxHealth;
    int damage;
    int id;

    public:

        int width; //todo(krekr) get image size
        int height;
        int x;
        int y;
        int dx; //delta x
        int dy; //delta y
        float speed; 
        float jumpSize;

        enemy(String name, int health, int damage)
        {
            this.heath = health;
            this.name = name;
            this.maxHealth = health;
            this.damage = damage;
            this id = for (int i = 0; i < id; i++) {this.id == i}
        }

        void getName();
        void getHealth();
        void getMaxHealth();
        void getDamage();
        void getId();

        void setName(string name);
        void setHealth(int health);
        void setMaxHealth(int maxHealth);
        void setDamage(int damage);
        void setId(int id);

}

enemy::getName()
{
    return this.name;
}

enemy::getHealth()
{
    return this.health;
}

enemy::getId()
{
    return this.id;
}

enemy::getMaxHealth()
{
    return this.maxHealth;
}

enemy::getDamage()
{
    return this.damage
}

enemy::setDamage(int damage)
{
    this.damage = damage;
}

enemy::setHealth(int health)
{
    this.health = health;
}

enemy::setId(int id)
{
    this.id = id;
}

enemy::setMaxHealth(int maxHealth)
{
    this.getMaxHealth = maxHealth;
}

enemy::setName(String name)
{
    this.name = name;
}