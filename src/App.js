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

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<HomePage />} />
          <Route path='/2Darray' element={<TwoDArrayPage />} />
          <Route path='/strings' element={<Strings1 />} />
          <Route path='/SingleDimensionArrays' element={<SingleDimensionArrays />} />
          <Route path='/SearchingAlgorithms' element={<SearchingAlgorithms />} />
          <Route path='/Recursion' element={<Recursion />} />
          <Route path='/LinkedList' element={<LinkedList />} />
          <Route path='/AboutUs' element={<AboutUs />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;