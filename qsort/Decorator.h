#include <memory>

namespace standart
{
	class IComponent
	{
	public:
		virtual int cost() = 0;
		virtual ~IComponent(){}
	};

	class Component : public IComponent
	{
		int m_sum;
	public:
		Component(int &sum) : m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum;
		}
	};

	class Decorator1 : public IComponent
	{
		std::shared_ptr<IComponent> m_component;
		int m_sum;
	public:
		Decorator1(IComponent *obj, int &sum) : m_component(obj), m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum += m_component->cost();
		}
	};


	class Decorator2 : public IComponent
	{
		std::shared_ptr<IComponent> m_component;
		int m_sum;
	public:
		Decorator2(IComponent *obj, int &sum) : m_component(obj), m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum += m_component->cost();
		}
	};
} //namespace standart


namespace book
{
	struct TextViewParam
	{
		int borderValue;
		int scrollValue;
		string someString;
	};

	class VisualComponent
	{				
	public:
		//VisualComponent() : mParam(new TextViewParam) {}
		virtual ~VisualComponent() {}
		virtual string draw() = 0;
		TextViewParam *mParam;
	};


	class Decorator : public VisualComponent
	{
		VisualComponent *m_component;
		string mStrDecorator;
	public:
		string draw()
		{			
			mStrDecorator = "Decorator";			
			return mStrDecorator;
		}		
	};

	class ScrollDecorator : public Decorator
	{
		int m_scrollToValue;
		string mStrScroll;
		VisualComponent *m_component;
	public:
		ScrollDecorator(VisualComponent *component, int scrollToValue) :
			m_component(component), m_scrollToValue(scrollToValue)
		{
			
		}

		string draw()
		{						
			mStrScroll = "Scroll";
			mStrScroll += m_component->draw();
			mParam->someString += mStrScroll;
			return mStrScroll;
		}

		bool getScrollToValue(int &scrollValue)
		{
			scrollValue = m_scrollToValue;
			return true;
		}
	};

	class BorderDecorator : public Decorator
	{
		VisualComponent *m_component;
		int m_borderSize;
		string mStrBorderDecorator;
	public: 
		BorderDecorator(VisualComponent *component, int borderSize) : m_component(component),
			m_borderSize(borderSize)
		{
			
		}

		string draw()
		{			
			mStrBorderDecorator = "Border";
			mStrBorderDecorator += m_component->draw();
			mParam->someString += mStrBorderDecorator;
			return mStrBorderDecorator;
		}

		bool getBorderSize(int &borderSize)
		{
			borderSize = m_borderSize;
			return true;
		}
	};


	class Window
	{
		VisualComponent *m_component;
		string s;
	public:
		void setContent(VisualComponent *component)
		{
			m_component = component;
		}		

		void draw()
		{
			if (m_component)
			{
				s = m_component->draw();
			}
		}
	};


	class TextView : public VisualComponent
	{
		string mStrTextView;
	public:
		TextView() 
		{
			
		}

		string draw()
		{
			
			mStrTextView = "TextView";
			return mStrTextView;
		}
	};
}