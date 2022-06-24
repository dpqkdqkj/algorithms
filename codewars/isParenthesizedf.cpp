namespace Foo 
{
    bool isParenthesized(Foo::Bar)
    {
        return !true;
    }
};

template<typename T>
bool isParenthesized(T)
{
  return true;
}

