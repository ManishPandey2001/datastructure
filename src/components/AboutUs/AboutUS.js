import React from "react";
import { Container, Row, Col, Card } from "react-bootstrap";
import "./AboutUs.css"; 

const AboutUs = () => {
  const team = [
    { name: "Bhavna", description: "4104/23" },
    { name: "Hema", description: "4021/23" },
    { name: "Sandhya", description: "4043/23" }
  ];

  return (
    <>
      {/* About Us Section */}
      <Container fluid className="hero-section text-light text-center">
        <Container>
          <Row>
            <Col>
              <h1>Meet the Team</h1>
              <p>We are three friends who created this platform to share our passion for data structures.</p>
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
