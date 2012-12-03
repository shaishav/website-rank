#ifndef PAGE_RANK
#define PAGE_RANK

// PageRank class implemented as a singleton implements Google's Page Rank algorithm and provides the ability to change the alpha factor 
class PageRank {

    public:
        ~PageRank();

        static PageRank& instance();

        float alpha();
        void setAlpha( float );

    private:
        PageRank( float );
        PageRank( const PageRank& );    // override compiler implementation of copy constructor
        void operator=( const PageRank& ); // not implemented either

        float m_alpha;

};


#endif
