import sqlalchemy
from sqlalchemy import create_engine
from sqlalchemy import Table, Column, Integer, String, ForeignKey, text
from sqlalchemy import select

from sqlalchemy.orm import Session
from sqlalchemy.orm import declarative_base
from sqlalchemy.orm import relationship

Base = declarative_base()

class User(Base):
  __tablename__ = "user" # type: ignore >>>
  user_id = Column(Integer, autoincrement= True, primary_key= True)
  username = Column(String, unique= True)
  email = Column(String, unique = True)
  # articles = relationship("Article", secondary="article_authors")

class Article(Base):
  __tablename__ = 'article'
  article_id = Column(Integer, primary_key=True, autoincrement=True)
  title = Column(String)
  content = Column(String)
  authors = relationship("User", secondary="article_authors")
  
class ArticleAuthors(Base):
  __tablename__ = 'article_authors'
  user_id = Column(Integer, ForeignKey('user.user_id'), primary_key=True, nullable=False)
  article_id = Column(Integer, ForeignKey('article.article_id'), primary_key=True, nullable=False)
  
engine = create_engine("sqlite:///../test.sqlite")

if __name__ == '__main__':
  with engine.connect() as connection:
    connection.execute(text("PRAGMA foreign_keys = ON"))
  # with Session(engine) as session:
  #   articles = session.query(Article)
  #   print("---------------Result---------------")
  #   for article in articles:
  #     print("Title: ", article.title)
  #     print("Content: " ,article.content)
  #     print("Authors: ",', '.join(str(i.username) for i in article.authors))
  #     print('\n')
  
  #  with Session(engine, autoflush=False) as session:
  #    session.begin()
  #    try:
  #      article = Article(title="my new article", content= "my new article content")
  #      session.add(article)
  #      session.flush()
       
  #      print(article.article_id)
  #      article_authors = ArticleAuthors(user_id = 1, article_id = article.article_id)
  #      session.add(article_authors)
  #      session.flush()
  #    except Exception as e:
  #      print("Rolling back due to error: ", e)
  #      session.rollback()
  #      raise 
  #    else:
  #       print("Commit")
  #       session.commit()
  with Session(engine, autoflush=False) as session:
    session.begin()
    try:
      author = session.query(User).filter(User.username == 'Gaurav Rana').one()
      article = Article(title="Insert using relationship", content= "User realationships to insert. It's easy")
      
      article.authors.append(author)
      session.add(article)
    except Exception as e:
      print("Exception, roling back", e)
      session.rollback()
    else:
      print("no exceptions, hence commit")
      session.commit()
      
       