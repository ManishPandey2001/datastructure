import React from "react";
import { Container, Row, Col, Card } from "react-bootstrap";
import "./AboutUs.css"; 

const AboutUs = () => {
  const team = [
    { name: "", description: "" },
    { name: "", description: "" },
    { name: "", description: "" }
  ];

  return (
    <>
      {/* About Us Section */}
      <Container fluid className="hero-section text-light text-center">
        <Container>
          <Row>
            <Col>
              <h1>Manish Pandey</h1>
              <p>I am a skilled Backend Developer with over 1.5 years of experience in building and maintaining scalable backend systems and APIs.
                 My expertise includes working with technologies like Node.js, NestJS, Sequelize, and TypeScript, alongside React for dynamic frontend development.
                 I have hands-on experience migrating microservices, optimizing database performance, and deploying applications using AWS and Vercel. 
                My projects include creating robust APIs, working on machine learning solutions with Azure ML Studio, and developing a responsive React portfolio application.I excel in problem-solving, team collaboration, and delivering efficient, high-quality code. 
                 With certifications in advanced backend development and a passion for continuous learning, I am well-equipped to contribute to both backend and full-stack projects.
              </p>
            </Col>
          </Row>
        </Container>
      </Container>

      {/* Team Section */}
      <Container className="features py-5">
        <Row xs={1} md={3} className="g-4">
          {team.map((member, index) => (
            <Col key={index}>
              <Card className="feature-card text-center">
                <Card.Body className="feature-link">
                  <Card.Title>{member.name}</Card.Title>
                  <Card.Text>{member.description}</Card.Text>
                </Card.Body>
              </Card>
            </Col>
          ))}
        </Row>
      </Container>
    </>
  );
};

export default AboutUs;
