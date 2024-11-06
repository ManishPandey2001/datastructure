import React from 'react';
import HomePage from './components/Home/HomePage';
import TwoDArrayPage from './components/2Darray/TwoDArrayPage';
import Strings1 from './components/strings/strings';
import SingleDimensionArrays from './components/singledimensionarrays/singleDimensionArrays';
import SearchingAlgorithms from './components/searchingalgorithms/searchingAlgorithms';
import Recursion from './components/recursion/recursion';
import LinkedList from './components/linkedlist/linkedList';
import { BrowserRouter, Route, Routes } from 'react-router-dom';
import AboutUs from './components/AboutUs/AboutUS';
import Sortingalgorithms from './components/sortingalgorithms/sortingalgorithms';
import Stack1 from './components/Stack/stack';
import Trees from './components/Trees/trees';
import Queque from './components/Queques/queques';
import Graphs from './components/graphs/graphs';

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<HomePage />} />
          <Route path='2Darray' element={<TwoDArrayPage />} />
          <Route path='/string' element={<Strings1 />} />
          <Route path='/SingleDimensionArray' element={<SingleDimensionArrays />} />
          <Route path='/SearchingAlgorithms' element={<SearchingAlgorithms />} />
          <Route path='/Recursion' element={<Recursion />} />
          <Route path='/LinkedList' element={<LinkedList />} />
          <Route path='/AboutUs' element={<AboutUs />} />
          <Route path='/Sortingalgorithms' element={<Sortingalgorithms />} />
          <Route path='/Stack' element={<Stack1 />} />
          <Route path='/Tree' element={<Trees />} />
          <Route path='/Queque' element={<Queque />} />
          <Route path='/Graph' element={<Graphs />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;